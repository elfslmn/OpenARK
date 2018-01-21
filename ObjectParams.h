#pragma once

#include "stdafx.h"
#include "version.h"

namespace ark {
    /**
     * Parameters for 3D object, plane, and hand detection
     */
    class ObjectParams {
    public:
        // Construct an instance of ObjectParams using default parameter values
        ObjectParams() {}

        // ** General parameters **

        /**
         * number of pixels around a point on a depth image to average when
         * converting ij (image) coordinates to xyz (world) coordinates
         * default: 9
         */
        int xyzAverageSize = 9;

        /**
         * pixels from the bottom edge of the depth map where a point is
         * considered to be connected to the edge (fingertips on edge are ignored)
         * default: 10
         */
        int bottomEdgeThresh = 10;

        /**
         * pixels from the left/right edges of the depth map where a point is
         * considered to be connected to the edge (fingertips on edge are ignored)
         * default: 10
         */
        int sideEdgeThresh = 10;

        // ** Hand detection parameters ** 

        /**
         * maximum distance in meters between points in the same cluster
         * (used in hand detection flood fill)
         * default: 0.004
         */
        float handClusterMaxDistance = 0.004;

        /**
         * minimum fraction of the points in a cluster over the total number of points visible
         * for the cluster to be considered as a hand candidate.
         * set to 0 to ignore.
         * default: 0.0167
         */
        float handClusterMinPoints = 0.0167;

        /**
         * number of pixels between consecutive seed points when initiating the hand detection flood fill
         * default: 10
         */
        int handClusterInterval = 10;

        /**
         * minimum surface area (square meters) of hand
         * default: 0.01
         */
        double handMinArea = 0.01;

        /**
         * maximum surface area (square meters) of hand
         * default: 0.056
         */
        double handMaxArea = 0.056;

        /**
         * if true, hand objects must touch the bottom/bottom-left/bottom-right
         * edge of the visible region
         * default: false
         */
        bool handRequireEdgeConnected = false;

        /**
         * max y-coordinate on the left and right sides (as fraction of image height)
         * to consider a cluster to be connected to the edge
         * default: 0.50
         */
        double handEdgeConnectMaxY = 0.50;

        /**
         * if set to false, disables the SVM used to eliminate objects unlikely to be hands.
         * default: true
         */
        bool handUseSVM = true;

        /**
         * @see handSVMHighConfidenceThresh
         * minimum SVM confidence value ([0...1]) for first hand object
         * default: 0.45
         */
        double handSVMConfidenceThresh = 0.45;

        /**
         * @see handSVMConfidenceThresh
         * minimum SVM confidence value ([0...1]) for additional hand objects
         * (only applied in queryHands)
         * default: 0.59
         */
        double handSVMHighConfidenceThresh = 0.59;

        /**
         * maximum distance between the center of the hand and the top point in the hand cluster (m)
         * used when detecting the hand's center
         */
        float centerMaxDistFromTop = 0.155;

        /**
         * pixels from the bottom edge of the depth map at which contour points are considered to be on the edge
         * usd while detecting contact points
         * default: 8
         */
        int contactBotEdgeThresh = 8;

        /**
         * pixels from the side edges of the depth map at which contour points are considered to be on the edge
         * usd while detecting contact points
         * default: 25
         */
        int contactSideEdgeThresh = 25;

        /**
         * minimum wrist width (m)
         * default: 0.030
         */
        float wristWidthMin = 0.030;

        /**
         * maximum wrist width (m)
         * default: 0.085
         */
        float wristWidthMax = 0.085;

        /**
         * maximum distance from the wrist to the center of the hand
         * default: 0.075
         */
        double wristCenterDistThresh = 0.075;

        /**
         * minimum finger length
         * default: 0.014
         */
        double fingerLenMin = 0.014;

        /**
         * maximum finger length
         * default: 0.125
         */
        double fingerLenMax = 0.125;

        /**
         * minimum distance between two finger tips
         * default: 0.01
         */
        double fingerDistMin = 0.01;

        /**
         * minimum value of (finger_y - defect_y)/abs(finger_x - defect_x) for any finger.
         * used to filter out low fingers.
         * default: -1.0
         */
        double fingerDefectSlopeMin = -1.0;

        /**
         * minimum value of (finger_y - center_y)/abs(finger_x - center_x) for any finger.
         * used to filter out low fingers.
         * default: -0.45
         */
        double fingerCenterSlopeMin = -0.45;

        /**
         * minimum curvature of the cluster's contour next to a finger tip
         * default: 0.95
         */
        double fingerCurveNearMin = 0.95;

        /**
         * maximum curvature of the cluster's contour next to a finger tip
         * default: 2.80
         */
        double fingerCurveNearMax = 2.80;

        /**
         * minimum curvature of the cluster's contour at a significant distance from the finger tip
         * default: 0.05
         */
        double fingerCurveFarMin = 0.05;

        /**
         * maximum curvature of the cluster's contour at a significant distance from the finger tip
         * default: 1.20
         */
        double fingerCurveFarMax = 1.20;

        /*
         * minimum finger length used when only one finger is detected
         * default: 0.04
         */
        double singleFingerLenMin = 0.04;

        /**
         * maximum finger length used when only one finger is detected
         * default: 0.11
         */
        double singleFingerLenMax = 0.11;

        /**
         * minimum angle formed by finger tip and neighboring defects
         * default: 0.08
         */
        double singleFingerAngleThresh = 0.08;

        /**
         * maximum angle formed by the start, far, and end points of a defect
         * default: 0.70 * PI
         */
        double defectMaxAngle = 0.70 * PI;

        /**
         * minimum distance from the end point of the previous defect to consider the
         * start point of the current defect as a finger candidate
         * default: 0.02
         */
        double defectMinDist = 0.02;

        /**
         * minimum distance from a defect's far point to the center (m)
         * default: 0.01
         */
        double defectFarCenterMinDist = 0.01;

        /**
         * minimum distance from a defect's far point to the center (m)
         * default: 0.105
         */
        double defectFarCenterMaxDist = 0.105;

        /**
         * minimum distance between the start and end points of a defect (m)
         * default: 0.01
         */
        double defectStartEndMinDist = 0.01;

        /**
         * maximum y-coord of a defect below the y-coord of the center point
         * default: 30
         */
        int defectMaxYFromCenter = 30;

        /**
         * minimum angle between centroid, defect, and finger
         * default: 0.40 * PI
         */
        double centroidDefectFingerAngleMin = 0.40 * PI;

        /**
         * minimum norm (distance squared; in m^2) between a hand and a plane.
         * points closer to the plane are not considered during hand detection
         * so that the hand is isolated from the planar surfaces are removed.
         * default: 0.000075
         */
        double handPlaneMinNorm = 0.000075;

        // ** Plane detection parameters ** 

        /**
         * resolution of normal map used in plane detection
         * default: 3
         */
        int normalResolution = 3;

        /**
         * maximum difference between the surface normal vectors of two adjacent points
         * to consider them as being on the same plane
         * (used in flood fill during plane detection)
         * default: 0.06
         */
        float planeFloodFillThreshold = 0.06;

        /**
         * fraction of outlier points to remove from the plane before performing regression
         * default: 0.5f
         */
        float planeOutlierRemovalThreshold = 0.5f;

        /**
         * minimum (# points / # total points on screen / normal resolution^2)
         * on a combined plane.
         * smaller planes are discarded.
         * default: 0.0650
         */
        float planeMinPoints = 0.0650;

        /**
         * minimum surface area (m^2) of a combined plane
         * default: 0.0300
         */
        double planeMinArea = 0.0300;

        /**
         * minimum (# equation inliers / # total points on screen * normal resolution^2)
         * on a combined plane
         * planes not meeting this criterion are discarded.
         * default: 0.0550
         */
        float planeEquationMinInliers = 0.0550;

        /**
         * minimum (# points / # total points on screen * normal resolution^2)
         * in a component of a greater plane
         * default: 0.0100
         */
        float subplaneMinPoints = 0.0100;

        /**
         * minimum surface area (m^2) of a component of a greater plane
         * default: 0.009
         */
        double subplaneMinArea = 0.009;

        /**
         * minimum (# points / # total points on screen * normal resolution^2)
         * for a plane to be considered a 'dominant' plane and thus removed 
         * prior to hand detection.
         * default: 0.200
         */
        double dominantPlaneMinPoints = 0.200;

        /**
         * minimum norm (r^2) between the equations of two 'subplanes'
         * to consider them separate planes.
         * if norm is lower, the two are combined into one larger plane object.
         * default: 0.0025
         */
        double planeCombineThreshold = 0.0025;


        /** Instance of ObjectParams initialized with default parameters */
        static const ObjectParams DEFAULT;
    };
}
