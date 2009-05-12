# $NetBSD: Makefile,v 1.1.1.1 2009/05/12 15:17:03 jihbed Exp $
#

DISTNAME=	IronPython-1.0.1-Src
PKGNAME=	ironpython-1.0.1
CATEGORIES=	lang python
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/ironpython/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.codeplex.com/IronPython
COMMENT=	Python implementation targeting the .NET and Mono platforms
#LICENSE=	LICENSE

PKG_DESTDIR_SUPPORT= user-destdir

WRKSRC=		${WRKDIR}/IronPython-1.0.1
USE_TOOLS+=	gmake
USE_LANGUAGES=	# none

SUBST_CLASSES+=		ipy.sh
SUBST_STAGE.ipy-sh=	post-build
SUBST_FILES.ipy-sh=	ipy.sh
SUBST_VARS.ipy-sh=	CMP EMULDIR MKDIR MV RM SED SH


DOCDIR=		${PREFIX}/share/doc/${PKGNAME}
LIBDIR=		${PREFIX}/lib/ironpython

INSTALLATION_DIRS+=	bin

post-extract:
	${CP} ${FILESDIR}/ipy.sh ${WRKSRC}
	${CP} ${FILESDIR}/ipyw.sh ${WRKSRC}

pre-build:
	${MKDIR} ${WRKSRC}/Src/IronPythonTest/bin

do-build:
	cd ${WRKSRC}/Src && ${GMAKE}

do-install:
	${CHMOD} +x  ${WRKSRC}/ipy.exe
	${CHMOD} +x  ${WRKSRC}/ipyw.exe
	${INSTALL_SCRIPT} ${WRKSRC}/ipy.sh ${PREFIX}/bin/ipy
	${INSTALL_SCRIPT} ${WRKSRC}/ipyw.sh ${PREFIX}/bin/ipyw
	${INSTALL_DATA_DIR} ${DESTDIR}${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/ipy.exe ${DESTDIR}${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/ipyw.exe ${DESTDIR}${LIBDIR}
	${INSTALL_DATA}	${WRKSRC}/IronMath.dll ${DESTDIR}${LIBDIR}
	${INSTALL_DATA}	${WRKSRC}/IronPython.dll ${DESTDIR}${LIBDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DESTDIR}${DOCDIR}


.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
