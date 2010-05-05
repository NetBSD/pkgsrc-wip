# $NetBSD: Makefile,v 1.2 2010/05/05 04:27:16 othyro Exp $
#

DISTNAME=	xebece-1.0.3
CATEGORIES=	misc
MASTER_SITES=	http://downloads.sourceforge.net/project/xebece/xebece/1.0.3/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xebece.sourceforge.net/
COMMENT=	Multipurpose tool for information visualization and organization
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/xebece-1.0
USE_LANGUAGES=	# none
USE_JAVA=	run

INSTALLATION_DIRS+=	bin share/doc/xebece share/examples/xebece xebece/dist
INSTALLATION_DIRS+=	xebece/lib

do-build:
		# nothing

post-build:
		${ECHO} '#!${SH}' > ${WRKSRC}/xebece
		${ECHO} '${DESTDIR}${PREFIX}/bin/sun6-java -jar ${DESTDIR}${PREFIX}/xebece/dist/xebece.jar' >> ${WRKSRC}/xebece

do-install:
		${INSTALL_DATA} ${WRKSRC}/doc/Xebece-Manual.cal ${DESTDIR}${PREFIX}/share/doc/xebece/Xebece-Manual.cal
		${INSTALL_DATA} ${WRKSRC}/doc/Xebece-Manual_de.cal ${DESTDIR}${PREFIX}/share/doc/xebece/Xebece-Manual_de.cal
		${INSTALL_DATA} ${WRKSRC}/doc/examples/chi.cal ${DESTDIR}${PREFIX}/share/examples/xebece/chi.cal
		${INSTALL_DATA} ${WRKSRC}/doc/examples/solar_system.cal ${DESTDIR}${PREFIX}/share/examples/xebece/solar_system.cal
		${INSTALL_SCRIPT} ${WRKSRC}/dist/xebece.jar ${DESTDIR}${PREFIX}/xebece/dist/xebece.jar
		${INSTALL_LIB} ${WRKSRC}/lib/icons.zip ${DESTDIR}${PREFIX}/xebece/lib/icons.zip
		${INSTALL_LIB} ${WRKSRC}/lib/prefuse.jar ${DESTDIR}${PREFIX}/xebece/lib/prefuse.jar
		${INSTALL_LIB} ${WRKSRC}/lib/prefusex.jar ${DESTDIR}${PREFIX}/xebece/lib/prefusex.jar
		${INSTALL_SCRIPT} ${WRKSRC}/xebece ${DESTDIR}${PREFIX}/bin/xebece

.include "../../lang/sun-jre6/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
