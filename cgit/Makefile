# $NetBSD: Makefile,v 1.8 2012/06/14 03:28:50 othyro Exp $

DISTNAME=	cgit-0.8.3
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://hjemli.net/git/cgit/snapshot/
EXTRACT_SUFX=	.tar.bz2

HOMEPAGE=	http://hjemli.net/git/cgit
COMMENT=	Fast web interface for git
MAINTAINER=	pkgsrc-wip-discuss@lists.sourceforge.net
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	curl>=7.19.2:../../www/curl

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		gmake
MAKE_FLAGS+=		GIT_VER=1.6.4.3
BUILD_MAKE_FLAGS+=	CGIT_CONFIG=${PKG_SYSCONFDIR}/cgitrc
BUILD_TARGET=		get-git all

CGIT_CONFIG=	${PKG_SYSCONFDIR}/cgitrc
CGIT_CGIBIN=	${PREFIX}/libexec/cgi-bin
CGIT_HTDOCS=	${PREFIX}/share/httpd/htdocs/cgit
CGIT_EGDIR=	${PREFIX}/share/examples

CONF_FILES=		${CGIT_EGDIR}/cgitrc ${CGIT_CONFIG}
INSTALLATION_DIRS=	libexec/cgi-bin share/httpd/htdocs/cgit

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cgit ${DESTDIR}${CGIT_CGIBIN}/cgit.cgi
	${INSTALL_DATA} ${WRKSRC}/cgit.png ${DESTDIR}${CGIT_HTDOCS}/cgit.png
	${INSTALL_DATA} ${WRKSRC}/cgit.css ${DESTDIR}${CGIT_HTDOCS}/cgit.css
	${INSTALL_DATA} ${WRKSRC}/cgitrc ${DESTDIR}${CGIT_EGDIR}/cgitrc

.include "../../mk/bsd.pkg.mk"
