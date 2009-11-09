# $NetBSD: Makefile,v 1.6 2009/11/09 15:05:17 christtrekker Exp $
#

DISTNAME=	lcdproc-0.5.3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lcdproc/}

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://lcdproc.org/
COMMENT=	Client/server software to print system info to small LCDs

PKG_DESTDIR_SUPPORT=	user-destdir
GNU_CONFIGURE=	yes

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=	${EGDIR}/LCDd.conf ${PKG_SYSCONFDIR}/LCDd.conf
CONF_FILES+=	${EGDIR}/lcdexec.conf ${PKG_SYSCONFDIR}/lcdexec.conf
CONF_FILES+=	${EGDIR}/lcdproc.conf ${PKG_SYSCONFDIR}/lcdproc.conf
CONF_FILES+=	${EGDIR}/lcdvc.conf ${PKG_SYSCONFDIR}/lcdvc.conf

post-patch:
	cp ${FILESDIR}/getopt.h ${WRKSRC}/shared

.include "../../mk/bsd.pkg.mk"
