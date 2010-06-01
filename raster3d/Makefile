# $NetBSD: Makefile,v 1.1.1.1 2010/06/01 06:32:38 obache Exp $
#

PKGNAME=	raster3d-2.7d
DISTNAME=	Raster3D_${PKGNAME:C/.*-//}
CATEGORIES=	graphics biology
MASTER_SITES=	http://skuld.bmsc.washington.edu/raster3d/		\
		http://mirror.inerd.com/FreeBSD/distfiles/raster3d/	\
		http://mirror.inerd.com/FreeBSD/distfiles/raster3d/old/

MAINTAINER=	shaun@inerd.com
HOMEPAGE=	http://skuld.bmsc.washington.edu/raster3d/
COMMENT=	Set of tools for generating raster images of proteins and molecules

FFLAGS:=	"${FFLAGS} -Wno-globals -L${LOCALBASE}/lib"

USE_LANGUAGES=	c fortran

DATADIR=	${PREFIX}/share/${PKGBASE}
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

BINARIES=	avs2ps balls rastep render ribbon rings3d rods normal3d
SCRIPTS=	label3d stereo3d

MANL=		avs2ps.l label3d.l r3d_objects.l rastep.l render.l rods.l \
		balls.l normal3d.l r3dtops.l raster3d.l ribbon.l stereo3d.l

PLIST_SUBST+=	DATADIR="${DATADIR:C/^${PREFIX}\///}"
PLIST_SUBST+=	DOCSDIR="${DOCSDIR:C/^${PREFIX}\///}"
PLIST_SUBST+=	EGDIR="${EGDIR:C/^${PREFIX}\///}"

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

#-----------------------------------------------------------------------

.include "../../mk/endian.mk"

OSDEFS=

.if ${OPSYS} != "IRIX" && ${OPSYS} != "SunOS"
OSDEFS=		-DLINUX
.endif

.if ${MACHINE_ENDIAN} == "little"
OSDEFS+=	-DNETWORKBYTEORDER
.endif

MAKE_ENV+=	OPSYS="${OPSYS}" OSDEFS="${OSDEFS}"

.if !empty(PKG_OPTIONS:Mmagick)
PLIST_SUBST+=	IMAGEMAGICK=""
.else
PLIST_SUBST+=	IMAGEMAGICK="@comment "
.endif

post-patch:
.if ${OPSYS} == "FreeBSD"
	${CP} ${.CURDIR}/files/in.h ${WRKSRC}/in.h
.endif

#-----------------------------------------------------------------------

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} netbsd

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/bin
	${INSTALL_MAN_DIR} ${PREFIX}/${PKGMANDIR}/manl

	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${BINARIES} ${PREFIX}/bin
.if !empty(PKG_OPTIONS:Mmagick)
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${SCRIPTS} ${PREFIX}/bin
.endif
	${INSTALL_DATA_DIR} ${DATADIR}/materials
	cd ${WRKSRC}/materials && ${INSTALL_DATA} * ${DATADIR}/materials
	cd ${WRKSRC}/doc && ${INSTALL_MAN} ${MANL} ${PREFIX}/${PKGMANDIR}/manl

	${INSTALL_DATA_DIR} ${DOCSDIR}/html
	cd ${WRKSRC}/doc && ${INSTALL_DATA} R3D_manual.pdf ${DOCSDIR}
	cd ${WRKSRC}/html && ${INSTALL_DATA} * ${DOCSDIR}/html

	${INSTALL_DATA_DIR} ${EGDIR}/msms
	cd ${WRKSRC}/examples && ${INSTALL_DATA} *.* ${EGDIR}
	cd ${WRKSRC}/examples/msms && ${INSTALL_DATA} * ${EGDIR}/msms

.if !empty(PKG_OPTIONS:Mmagick)
.  include "../../graphics/ImageMagick/buildlink3.mk"
.endif

.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
