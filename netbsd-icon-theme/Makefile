# $NetBSD: Makefile,v 1.2 2012/10/03 18:15:31 asau Exp $
#

DISTNAME=	netbsd-icon-theme-0.0
CATEGORIES=	graphics
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
# TODO: point to wiki for this package
HOMEPAGE=	http://wiki.NetBSD.org/
COMMENT=	Icon theme for NetBSD
#LICENSE=	# TODO: (see mk/license.mk)

#TODO: no icons are added yet; see the comments in the PLIST
#        gnome-main-menu.svg
#        novell-button.svg
#        start-here.svg
#        distributor-logo.svg

# Note: the index.theme inherits elementary-mono-dark
DEPENDS=	elementary-icon-theme>=0:../../wip/elementary-icon-theme

NO_CHECKSUM=	yes
NO_BUILD=	yes
USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	share/icons/netbsd

do-install:
	${INSTALL_DATA} ${FILESDIR}/index.theme \
		${DESTDIR}${PREFIX}/share/icons/netbsd/index.theme

.include "../../mk/bsd.pkg.mk"
