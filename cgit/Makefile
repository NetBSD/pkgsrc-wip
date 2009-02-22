# $NetBSD: Makefile,v 1.2 2009/02/22 02:41:44 mstapelberg Exp $

CATEGORIES=www
DISTNAME=cgit-0.8.2
HOMEPAGE=http://hjemli.net/git/cgit
COMMENT=Fast web interface for git

USE_TOOLS+=gmake
MAKE_ENV+=GIT_VER=1.6.0.6
BUILD_MAKE_FLAGS+=CGIT_CONFIG=${PKG_SYSCONFDIR}/cgitrc
BUILD_TARGET=get-git all

PKG_DESTDIR_SUPPORT=user-destdir
BUILD_DEPENDS+= curl-7.19.2:../../www/curl

MASTER_SITES=http://hjemli.net/git/cgit/snapshot/
DISTFILES=cgit-0.8.2.tar.bz2

CGIT_CONFIG=	${PKG_SYSCONFDIR}/cgitrc
CGIT_CGIBIN=	${PREFIX}/libexec/cgi-bin
CGIT_HTDOCS=	${PREFIX}/share/httpd/htdocs/cgit
CGIT_EGDIR=	${PREFIX}/share/examples

CONF_FILES= ${CGIT_EGDIR}/cgitrc ${CGIT_CONFIG}
INSTALLATION_DIRS= libexec/cgi-bin share/httpd/htdocs/cgit

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cgit ${DESTDIR}${CGIT_CGIBIN}/cgit.cgi
	${INSTALL_DATA} ${WRKSRC}/cgit.png ${DESTDIR}${CGIT_HTDOCS}/cgit.png
	${INSTALL_DATA} ${WRKSRC}/cgit.css ${DESTDIR}${CGIT_HTDOCS}/cgit.css
	${INSTALL_DATA} ${WRKSRC}/cgitrc ${DESTDIR}${CGIT_EGDIR}/cgitrc

.include "../../mk/bsd.pkg.mk"
