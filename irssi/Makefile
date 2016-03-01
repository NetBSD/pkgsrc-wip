# $NetBSD: Makefile,v 1.68 2015/06/12 10:48:27 wiz Exp $

DISTNAME=		${IRSSI_DISTNAME}
PKGREVISION=		1
CATEGORIES=		chat
EXTRACT_SUFX=		${IRSSI_EXTRACT_SUFX}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.irssi.org/
COMMENT=		Secure and modular IRC client with text mode user interface
LICENSE=		gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"
.include "Makefile.common"

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		perl gettext autoconf automake autoreconf pkg-config

CONFIGURE_ARGS+=	--with-terminfo \
			--with-proxy \
			--without-ncurses \
			--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/irssi
CONF_FILES=	${EGDIR}/irssi.conf ${PKG_SYSCONFDIR}/irssi.conf

INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

MAKE_ENV+=	DATE="20160208 10:18:00"

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "options.mk"
.include "../../devel/glib2/buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/irssi-config ${DESTDIR}${IRSSI_CONFIG}

# tries to run lynx in autogen.sh (or links, elinks)
BUILD_DEPENDS+= lynx-[0-9]*:../../www/lynx

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
