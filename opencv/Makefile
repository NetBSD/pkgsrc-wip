# $NetBSD: Makefile,v 1.163 2026/06/28 15:41:22 wiz Exp $

.include "Makefile.common"

DISTNAME=	opencv-${OPENCV_VERSION}

MAINTAINER=	anthony.mallet@laas.fr
COMMENT=	Library for computer vision problems

PY_PATCHPLIST=		yes
REPLACE_PYTHON+=	samples/python/*.py

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

CMAKE_CONFIGURE_ARGS+=	-DPYTHON_EXECUTABLE=${PYTHONBIN}

PLIST_VARS+=	opencl

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Darwin"
PLIST.opencl=	yes
.endif

.include "options.mk"

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/lib
# For Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/lib
TEST_TARGET=	test

# https://github.com/fkenmar/opencv/commit/142801f769ed4946a161f62738bac5a5fe56a60f
post-extract:
	${RM} -f ${WRKSRC}/modules/dnn/misc/caffe/opencv-caffe.pb.cc
	${RM} -f ${WRKSRC}/modules/dnn/misc/caffe/opencv-caffe.pb.h
	${RM} -f ${WRKSRC}/modules/dnn/src/caffe/caffe_io.cpp
	cd ${WRKSRC} && ${MV} modules/dnn/src/caffe/glog_emulator.hpp modules/dnn/src/glog_emulator.hpp
	cd ${WRKSRC} && ${MV} modules/dnn/src/caffe/caffe_io.hpp modules/dnn/src/protobuf_io.hpp

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/licenses/opencv5 ${DESTDIR}${PREFIX}/share/opencv5/licenses

.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/libavif/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
BUILDLINK_API_DEPENDS.openjpeg+=	openjpeg>=2.3.1
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
