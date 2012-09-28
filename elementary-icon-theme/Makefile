# $NetBSD: Makefile,v 1.2 2012/09/28 22:07:31 asau Exp $
#

DISTNAME=	elementary-icon-theme-2.7.1
CATEGORIES=	graphics
MASTER_SITES=	https://launchpad.net/elementaryicons/2.0/2.7.1/+download/

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	http://elementaryos.org/docs/packaging/themes/elementary-icons
COMMENT=	Simple and appealing Tango-styled icon theme
#LICENSE=	# TODO: (see mk/license.mk)

# Needed for launchpad
FETCH_USING=	curl

WRKSRC=		${WRKDIR}/elementary-icon-theme
NO_BUILD=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	pax

post-extract:
	${CHMOD} a-x ${WRKSRC}/elementary/apps/48/internet-mail.svg
	
do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/icons
	cd ${WRKSRC} && pax -rw -pe . ${DESTDIR}${PREFIX}/share/icons/

.include "../../mk/bsd.pkg.mk"
