# $NetBSD: Makefile,v 1.5 2009/07/28 22:22:16 rsmarples Exp $

CATEGORIES=www
DISTNAME=cgit-0.8.2.1
PKGREVISION=1
HOMEPAGE=http://hjemli.net/git/cgit
COMMENT=Fast web interface for git

USE_TOOLS+=gmake
MAKE_JOBS_SAFE=no
MAKE_FLAGS+=GIT_VER=1.6.3.3
BUILD_MAKE_FLAGS+=CGIT_CONFIG=${PKG_SYSCONFDIR}/cgitrc
BUILD_TARGET=get-git all

PKG_DESTDIR_SUPPORT=user-destdir
BUILD_DEPENDS+= curl>=7.19.2:../../www/curl

MASTER_SITES=http://hjemli.net/git/cgit/snapshot/
DISTFILES=${DISTNAME}.tar.bz2

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
