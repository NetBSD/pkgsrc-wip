# $NetBSD: Makefile,v 1.2 2003/12/01 06:21:05 mpasternak Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1998/08/09 15:13:33 kuriyama Exp
# and now we!
# $Id: Makefile,v 1.2 2003/12/01 06:21:05 mpasternak Exp $
#

DISTNAME=		gettext-0.11.5
PKGNAME=		${MINGW_PKG_PREFIX}gettext-lib-0.11.5
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=gettext/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.gnu.org/software/gettext/gettext.html
COMMENT=		Tools for providing messages in different languages, libintl only

GNU_CONFIGURE=		# defined
USE_LIBTOOL=		yes
USE_BUILDLINK2=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
CONFIG_GUESS_OVERRIDE=	${WRKSRC}/config.guess
CONFIG_SUB_OVERRIDE=	${WRKSRC}/config.sub
CONFIGURE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"
MAKE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"

ALL_TARGET=		all-yes
INSTALL_TARGET=		install-exec
BUILD_DIRS=		${WRKSRC}/intl

BUILD_DEPENDS=		${MINGW_PKG_PREFIX}libiconv>=1.9.1:../../wip/mingw32-libiconv

.include "../../wip/mk/win32.pkg.mk"
