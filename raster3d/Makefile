# $NetBSD: Makefile,v 1.2 2010/06/01 08:14:50 obache Exp $
#

DISTNAME=	Raster3D_2.7s
PKGNAME=	${DISTNAME:S/_/-/:tl}
CATEGORIES=	graphics biology
MASTER_SITES=	http://skuld.bmsc.washington.edu/raster3d/

MAINTAINER=	shaun@inerd.com
HOMEPAGE=	http://skuld.bmsc.washington.edu/raster3d/
COMMENT=	Set of tools for generating raster images of proteins and molecules

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c fortran
USE_TOOLS+=	gunzip:run

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

.include "../../mk/endian.mk"

OSDEFS=

.if ${OPSYS} != "IRIX" && ${OPSYS} != "SunOS"
OSDEFS+=	-DLINUX
.endif

.if ${MACHINE_ENDIAN} == "little"
OSDEFS+=	-DNETWORKBYTEORDER
.endif

MAKE_FLAGS+=	OS=${OPSYS:Q} OSDEFS=${OSDEFS:Q} RM=${RM:Q}

.include "../../mk/compiler.mk"
.if !empty(FCPATH:M*g77*) || !empty(FCPATH:M*f2c*)
do-configure:
	cd ${WRKSRC} && env ${MAKE_ENV} ${MAKE} strip-for-g77
.endif

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/manl

	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${BINARIES} ${DESTDIR}${PREFIX}/bin
.if !empty(PKG_OPTIONS:Mimagemagick)
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${SCRIPTS} ${DESTDIR}${PREFIX}/bin
.endif
	${INSTALL_DATA_DIR} ${DESTDIR}${DATADIR}/materials
	cd ${WRKSRC}/materials && ${INSTALL_DATA} * ${DESTDIR}${DATADIR}/materials
	cd ${WRKSRC}/doc && ${INSTALL_MAN} ${MANL} ${DESTDIR}${PREFIX}/${PKGMANDIR}/manl

	${INSTALL_DATA_DIR} ${DESTDIR}${DOCSDIR}/html
	cd ${WRKSRC}/doc && ${INSTALL_DATA} R3D_manual.pdf ${DESTDIR}${DOCSDIR}
	cd ${WRKSRC}/html && ${INSTALL_DATA} * ${DESTDIR}${DOCSDIR}/html

	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}/msms
	cd ${WRKSRC}/examples && ${INSTALL_DATA} *.* ${DESTDIR}${EGDIR}
	cd ${WRKSRC}/examples/msms && ${INSTALL_DATA} * ${DESTDIR}${EGDIR}/msms

.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
