# $NetBSD$

GITHUB_PROJECT=	video2x
GITHUB_TAG=	6.3.1
DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=k4yt3x/}
DIST_SUBDIR=	${GITHUB_PROJECT}

REALESRGAN_TAG=	cd68df6f98f036fcc9e7d63597ea6faa427c2d2d
RIFE_TAG=	f2edda49a5fd817a7137509e54e70d2e30d9b684
REALCUGAN_TAG=	52f598265a973fc8b17eb5e13cddc0e71c0a79dc

DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	librealesrgan-ncnn-vulkan-${REALESRGAN_TAG}.tar.gz
DISTFILES+=	librealcugan-ncnn-vulkan-${REALCUGAN_TAG}.tar.gz
DISTFILES+=	librife-ncnn-vulkan-${RIFE_TAG}.tar.gz

SITES.librealesrgan-ncnn-vulkan-${REALESRGAN_TAG}.tar.gz= \
	-https://github.com/k4yt3x/librealesrgan-ncnn-vulkan/archive/${REALESRGAN_TAG}.tar.gz
SITES.librealcugan-ncnn-vulkan-${REALCUGAN_TAG}.tar.gz= \
	-https://github.com/k4yt3x/librealcugan-ncnn-vulkan/archive/${REALCUGAN_TAG}.tar.gz
SITES.librife-ncnn-vulkan-${RIFE_TAG}.tar.gz= \
	-https://github.com/k4yt3x/librife-ncnn-vulkan/archive/${RIFE_TAG}.tar.gz

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://github.com/k4yt3x/video2x/
COMMENT=	Machine learning-based lossless video super resolution framework
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++
LDFLAGS+=	-Wl,--allow-shlib-undefined

CMAKE_CONFIGURE_ARGS+=		-DCMAKE_CXX_COMPILER_AR="/usr/bin/ar"
CMAKE_MODULE_PATH_OVERRIDE+=	third_party/librealesrgan_ncnn_vulkan/src/CMakeLists.txt
CMAKE_MODULE_PATH_OVERRIDE+=	third_party/librife_ncnn_vulkan/src/CMakeLists.txt

post-extract:
	${MV} ${WRKDIR}/librealesrgan-ncnn-vulkan-${REALESRGAN_TAG}/src \
		${WRKSRC}/third_party/librealesrgan_ncnn_vulkan
	${MV} ${WRKDIR}/librealcugan-ncnn-vulkan-${REALCUGAN_TAG}/src \
		${WRKSRC}/third_party/librealcugan_ncnn_vulkan
	${MV} ${WRKDIR}/librife-ncnn-vulkan-${RIFE_TAG}/models \
		${WRKSRC}/third_party/librife_ncnn_vulkan
	${MV} ${WRKDIR}/librife-ncnn-vulkan-${RIFE_TAG}/src \
		${WRKSRC}/third_party/librife_ncnn_vulkan

.include "../../devel/cmake/build.mk"

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/spdlog/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/opencv/buildlink3.mk"
.include "../../multimedia/ffmpeg7/buildlink3.mk"
.include "../../wip/ncnn/buildlink3.mk"
BUILDLINK_FILES.glslang+=	bin/glslang bin/spirv-remap
.include "../../wip/glslang/buildlink3.mk"
.include "../../wip/vulkan-loader/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
