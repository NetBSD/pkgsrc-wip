# $NetBSD: Makefile,v 1.11 2010/01/11 21:21:28 christtrekker Exp $
#

DISTNAME=	lcdproc-0.5.3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lcdproc/}

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://lcdproc.org/
COMMENT=	Client/server software to print system info to small LCDs

PKG_DESTDIR_SUPPORT=	user-destdir
GNU_CONFIGURE=	yes

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

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=	${EGDIR}/LCDd.conf ${PKG_SYSCONFDIR}/LCDd.conf
CONF_FILES+=	${EGDIR}/lcdexec.conf ${PKG_SYSCONFDIR}/lcdexec.conf
CONF_FILES+=	${EGDIR}/lcdproc.conf ${PKG_SYSCONFDIR}/lcdproc.conf
CONF_FILES+=	${EGDIR}/lcdvc.conf ${PKG_SYSCONFDIR}/lcdvc.conf

post-patch:
	${CP} ${FILESDIR}/getopt.h ${WRKSRC}/shared

.include "../../mk/bsd.pkg.mk"
