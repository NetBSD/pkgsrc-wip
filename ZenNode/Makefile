# $NetBSD$

DISTNAME=	zennode-1.2.1
PKGNAME=	${DISTNAME:S/zennode/ZenNode/}
CATEGORIES=	games
MASTER_SITES=	http://www.mrousseau.org/programs/ZenNode/archives/
EXTRACT_SUFX=	.zip

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://www.mrousseau.org/programs/ZenNode/
COMMENT=	Node/blockmap/reject builder for Doom and Hexen level formats
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake unzip
BUILD_DIRS=	src/ZenNode
MAKE_FILE=	makefile

ZENNODE_DOCS=	Custom.html History.html Overview.html README.html RMB.html \
		bspdiff.html bspinfo.html compare.html index.html main.css \
		manual.html

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/ZenNode

post-extract:
	cd ${WRKSRC} ; unzip zennode-src.zip

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ZenNode/ZenNode	\
		${DESTDIR}${PREFIX}//bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/ZenNode/bspdiff	\
		${DESTDIR}${PREFIX}//bin/ZenNode-bspdiff
	${INSTALL_PROGRAM} ${WRKSRC}/src/ZenNode/bspinfo	\
		${DESTDIR}${PREFIX}//bin/ZenNode-bspinfo
	${INSTALL_PROGRAM} ${WRKSRC}/src/ZenNode/compare	\
		${DESTDIR}${PREFIX}//bin/ZenNode-compare
	cd ${WRKSRC} ; for zennode_file in ${ZENNODE_DOCS} ; 	\
	do							\
		${INSTALL_DATA} ${WRKSRC}/doc/$${zennode_file}	\
			${DESTDIR}${PREFIX}/share/doc/ZenNode ;	\
	done

.include "../../mk/bsd.pkg.mk"
