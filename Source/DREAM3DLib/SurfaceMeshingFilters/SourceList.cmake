#--////////////////////////////////////////////////////////////////////////////
#-- Your License or copyright can go here
#--////////////////////////////////////////////////////////////////////////////

set(DREAM3D_FILTER_GROUP_NAME SurfaceMeshingFilters)
set(${DREAM3D_FILTER_GROUP_NAME}_FILTERS_HDRS "")

START_FILTER_GROUP(${FilterWidgetsLib_BINARY_DIR} "${DREAM3D_FILTER_GROUP_NAME}")

ADD_DREAM3D_FILTER( "DREAM3DLib" "FilterWidgetsLib" ${DREAM3D_FILTER_GROUP_NAME} GenerateSurfaceMeshConnectivity TRUE)
ADD_DREAM3D_FILTER( "DREAM3DLib" "FilterWidgetsLib" ${DREAM3D_FILTER_GROUP_NAME} GenerateUniqueEdges FALSE)
ADD_DREAM3D_FILTER( "DREAM3DLib" "FilterWidgetsLib" ${DREAM3D_FILTER_GROUP_NAME} LaplacianSmoothing TRUE)
ADD_DREAM3D_FILTER( "DREAM3DLib" "FilterWidgetsLib" ${DREAM3D_FILTER_GROUP_NAME} M3CSliceBySlice TRUE)
ADD_DREAM3D_FILTER( "DREAM3DLib" "FilterWidgetsLib" ${DREAM3D_FILTER_GROUP_NAME} MovingFiniteElementSmoothing TRUE)
ADD_DREAM3D_FILTER( "DREAM3DLib" "FilterWidgetsLib" ${DREAM3D_FILTER_GROUP_NAME} QuickSurfaceMesh TRUE)
ADD_DREAM3D_FILTER( "DREAM3DLib" "FilterWidgetsLib" ${DREAM3D_FILTER_GROUP_NAME} ReverseTriangleWinding TRUE)
ADD_DREAM3D_FILTER( "DREAM3DLib" "FilterWidgetsLib" ${DREAM3D_FILTER_GROUP_NAME} SharedGrainFaceFilter TRUE)
ADD_DREAM3D_FILTER( "DREAM3DLib" "FilterWidgetsLib" ${DREAM3D_FILTER_GROUP_NAME} TriangleCentroidFilter TRUE)
ADD_DREAM3D_FILTER( "DREAM3DLib" "FilterWidgetsLib" ${DREAM3D_FILTER_GROUP_NAME} TriangleNormalFilter TRUE)
ADD_DREAM3D_FILTER( "DREAM3DLib" "FilterWidgetsLib" ${DREAM3D_FILTER_GROUP_NAME} VerifyTriangleWinding TRUE)


ADD_DREAM3D_SUPPORT_HEADER(${DREAM3DLib_SOURCE_DIR} ${DREAM3D_FILTER_GROUP_NAME} SurfaceMeshFilter.h)
ADD_DREAM3D_SUPPORT_HEADER(${DREAM3DLib_SOURCE_DIR} ${DREAM3D_FILTER_GROUP_NAME} SurfaceMeshFilter.cpp)

ADD_DREAM3D_SUPPORT_HEADER(${DREAM3DLib_SOURCE_DIR} ${DREAM3D_FILTER_GROUP_NAME} MeshTriangleNeighbors.hpp)
ADD_DREAM3D_SUPPORT_HEADER(${DREAM3DLib_SOURCE_DIR} ${DREAM3D_FILTER_GROUP_NAME} MeshVertLinks.hpp)

ADD_DREAM3D_SUPPORT_HEADER(${DREAM3DLib_SOURCE_DIR} ${DREAM3D_FILTER_GROUP_NAME} BinaryNodesTrianglesReader.h)
ADD_DREAM3D_SUPPORT_SOURCE(${DREAM3DLib_SOURCE_DIR} ${DREAM3D_FILTER_GROUP_NAME} BinaryNodesTrianglesReader.cpp)

ADD_DREAM3D_SUPPORT_HEADER(${DREAM3DLib_SOURCE_DIR} ${DREAM3D_FILTER_GROUP_NAME} MeshFunctions.h)
ADD_DREAM3D_SUPPORT_HEADER(${DREAM3DLib_SOURCE_DIR} ${DREAM3D_FILTER_GROUP_NAME} MeshLinearAlgebra.h)

ADD_DREAM3D_SUPPORT_HEADER(${DREAM3DLib_SOURCE_DIR} ${DREAM3D_FILTER_GROUP_NAME} FindNRingNeighbors.h)
ADD_DREAM3D_SUPPORT_SOURCE(${DREAM3DLib_SOURCE_DIR} ${DREAM3D_FILTER_GROUP_NAME} FindNRingNeighbors.cpp)

ADD_DREAM3D_SUPPORT_HEADER(${DREAM3DLib_SOURCE_DIR} ${DREAM3D_FILTER_GROUP_NAME} util/Vector3.h)
ADD_DREAM3D_SUPPORT_SOURCE(${DREAM3DLib_SOURCE_DIR} ${DREAM3D_FILTER_GROUP_NAME} util/Vector3.cpp)

ADD_DREAM3D_SUPPORT_HEADER(${DREAM3DLib_SOURCE_DIR} ${DREAM3D_FILTER_GROUP_NAME} util/Plane.h)
ADD_DREAM3D_SUPPORT_SOURCE(${DREAM3DLib_SOURCE_DIR} ${DREAM3D_FILTER_GROUP_NAME} util/Plane.cpp)

ADD_DREAM3D_SUPPORT_HEADER(${DREAM3DLib_SOURCE_DIR} ${DREAM3D_FILTER_GROUP_NAME} util/TriangleOps.h)
ADD_DREAM3D_SUPPORT_SOURCE(${DREAM3DLib_SOURCE_DIR} ${DREAM3D_FILTER_GROUP_NAME} util/TriangleOps.cpp)

ADD_DREAM3D_SUPPORT_HEADER(${DREAM3DLib_SOURCE_DIR} ${DREAM3D_FILTER_GROUP_NAME} util/Exception.h)
ADD_DREAM3D_SUPPORT_HEADER(${DREAM3DLib_SOURCE_DIR} ${DREAM3D_FILTER_GROUP_NAME} util/InvalidParameterException.h)

if(EIGEN_FOUND)
  ADD_DREAM3D_FILTER( "DREAM3DLib" "FilterWidgetsLib" ${DREAM3D_FILTER_GROUP_NAME} GrainFaceCurvatureFilter TRUE)

  ADD_DREAM3D_SUPPORT_HEADER(${DREAM3DLib_SOURCE_DIR} ${DREAM3D_FILTER_GROUP_NAME} CalculateTriangleGroupCurvatures.h)
  ADD_DREAM3D_SUPPORT_SOURCE(${DREAM3DLib_SOURCE_DIR} ${DREAM3D_FILTER_GROUP_NAME} CalculateTriangleGroupCurvatures.cpp)
endif()
