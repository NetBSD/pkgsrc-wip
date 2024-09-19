# $NetBSD$

DISTNAME=	lanq-0.6.3
CATEGORIES=	lang
MASTER_SITES=	https://svwh.dl.sourceforge.net/project/lanq/LanQ/0.6.3/
EXTRACT_SUFX=	.jar

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://lanq.sourceforge.net/
COMMENT=	Quantum imperative programming language
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}

NO_BUILD=		yes
PKG_JVMS_ACCEPTED=	sun-jdk7 jdk15 jdk16 openjdk8 openjdk11


INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar ${DESTDIR}${PREFIX}/bin/${DISTNAME}.jar

.include "../../mk/bsd.pkg.mk"
