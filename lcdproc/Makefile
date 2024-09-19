# $NetBSD: Makefile,v 1.12 2012/10/03 09:10:35 asau Exp $
#

DISTNAME=	lcdproc-0.5.9
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=lcdproc/}
GITHUB_PROJECT=	lcdproc
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://lcdproc.org/
COMMENT=	Client/server software to print system info to small LCDs
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-drivers=all
CONFIGURE_ARGS+=	--disable-libX11
CONFIGURE_ARGS+=	--disable-libpng
CONFIGURE_ARGS+=	--disable-freetype
USE_TOOLS+=		pkg-config

.include "../../mk/bsd.prefs.mk"
REPLACE_PERL+=	clients/examples/fortune.pl \
		clients/examples/iosock.pl \
		clients/examples/tail.pl \
		clients/examples/x11amp.pl \
		clients/examples/lcdident.pl \
		clients/metar/lcdmetar.pl
# Solaris /bin/sh is really bad, so use TOOLS_PLATFORM.sh if it's been defined.
.if ${OPSYS} == "SunOS"
REPLACE_SH+=	compile config.guess config.sub configure depcomp \
		install-sh missing \
		scripts/init-LCDd.LSB.in \
		scripts/init-LCDd.debian.in \
		scripts/init-LCDd.rpm.in \
		scripts/init-lcdexec.LSB.in \
		scripts/init-lcdexec.debian.in \
		scripts/init-lcdproc.LSB.in \
		scripts/init-lcdproc.debian.in \
		scripts/init-lcdproc.rpm.in \
		scripts/init-lcdvc.LSB.in \
		scripts/init-lcdvc.debian.in \
		contrib/interface-demo2/scripts/MyHalt \
		contrib/interface-demo2/scripts/MyIPSet \
		contrib/interface-demo2/scripts/MyReboot
.endif

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Fixing the driver path.
SUBST_FILES.path=	LCDd.conf
SUBST_SED.path=		-e "s,server/drivers,${PREFIX}/lib/lcdproc,g"

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}
CONF_FILES=		${EGDIR}/LCDd.conf ${PKG_SYSCONFDIR}/LCDd.conf
CONF_FILES+=		${EGDIR}/lcdexec.conf ${PKG_SYSCONFDIR}/lcdexec.conf
CONF_FILES+=		${EGDIR}/lcdproc.conf ${PKG_SYSCONFDIR}/lcdproc.conf
CONF_FILES+=		${EGDIR}/lcdvc.conf ${PKG_SYSCONFDIR}/lcdvc.conf

.include "../../devel/libftdi1/buildlink3.mk"
.include "../../devel/libhid/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/libusb.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
