# $NetBSD: Makefile,v 1.1 2012/12/01 12:56:22 othyro Exp $
#

DISTNAME=	rapidxml-1.13
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rapidxml/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rapidxml.sourceforge.net/
COMMENT=	RapidXml is an attempt to create the fastest XML parser possible
LICENSE=	boost-license OR mit

USE_LANGUAGES=		# none
NO_CONFIGURE=		yes
NO_BUILD=		yes
INSTALLATION_DIRS+=	include/rapidxml share/doc/rapidxml

do-install:
	cd ${WRKSRC} && \
		${INSTALL_DATA} *.hpp ${DESTDIR}${PREFIX}/include/rapidxml/ && \
		${INSTALL_DATA} manual.html ${DESTDIR}${PREFIX}/share/doc/rapidxml/

.include "../../mk/bsd.pkg.mk"
