# $NetBSD: Makefile,v 1.7 2012/09/30 05:44:15 asau Exp $
#

DISTNAME=	IronPython-1.0.1-Src
PKGNAME=	ironpython-1.0.1
PKGREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/ironpython/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.codeplex.com/IronPython
COMMENT=	Python implementation targeting the .NET and Mono platforms
#LICENSE=	LICENSE

WRKSRC=		${WRKDIR}/IronPython-1.0.1
USE_TOOLS+=	gmake
USE_LANGUAGES=	# none

SUBST_CLASSES+=		ipy.sh
SUBST_STAGE.ipy-sh=	post-build
SUBST_FILES.ipy-sh=	ipy.sh
SUBST_VARS.ipy-sh=	CMP EMULDIR MKDIR MV RM SED SH


DOCDIR=		${PREFIX}/share/doc/${PKGNAME}

INSTALLATION_DIRS+=	bin lib/ironpython

post-extract:
	${CP} ${FILESDIR}/ipy.sh ${WRKSRC}

pre-build:
	${MKDIR} ${WRKSRC}/Src/IronPythonTest/bin

do-build:
	cd ${WRKSRC}/Src && ${GMAKE}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ipy.sh ${DESTDIR}${PREFIX}/bin/ironpython
	${CHMOD} +x  ${DESTDIR}${PREFIX}/bin/ironpython
	${INSTALL_DATA} ${WRKSRC}/ipy.exe ${DESTDIR}${PREFIX}/lib/ironpython
	${INSTALL_DATA} ${WRKSRC}/ipyw.exe ${DESTDIR}${PREFIX}/lib/ironpython
	${INSTALL_LIB}	${WRKSRC}/IronMath.dll ${DESTDIR}${PREFIX}/lib/ironpython
	${INSTALL_LIB}	${WRKSRC}/IronPython.dll ${DESTDIR}${PREFIX}/lib/ironpython
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DESTDIR}${DOCDIR}


.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
