# $NetBSD: Makefile,v 1.3 2012/11/03 19:41:31 kristerw Exp $
#

DISTNAME=	tuxguitar-src-1.2
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tuxguitar/}

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://www.tuxguitar.com.ar/
COMMENT=	Multitrack tablature editor and player
LICENSE=	gnu-lgpl-v2

WRKSRC=		${WRKDIR}/tuxguitar-src-1.2
USE_LANGUAGES=	c c++
USE_JAVA2=	yes

BUILD_DEPENDS+=	apache-ant-[0-9]*:../../devel/apache-ant
MAKE_PROGRAM=	ant
MAKE_FILE=	build.xml

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

NO_CONFIGURE=	yes

do-build:
.for optn in ${PKG_OPTIONS}
	${MAKE_PROGRAM} -f ${WRKSRC}/TuxGuitar-${optn}/${MAKE_FILE}
	${CP} ${WRKSRC}/TuxGuitar-${optn}/tuxguitar-${optn}.jar ${WRKSRC}/TuxGuitar/share/plugins
.endfor
	${MAKE_PROGRAM} -f ${WRKSRC}/TuxGuitar/${MAKE_FILE}

.include "../../devel/swt/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
