# $NetBSD: Makefile,v 1.3 2011/07/20 20:55:42 astforge Exp $
#

DISTNAME=	nostromo-1.9.4
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.nazgul.ch/dev/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ast@marabu.ch
HOMEPAGE=	http://www.nazgul.ch/dev_nostromo.html
COMMENT=	Fast, secure HTTP/1.1 CGI/1.1 SSL IPv4/IPv6 webserver
LICENSE=	modified-bsd

USE_LANGUAGES=	c
USE_TOOLS=	sed

PKG_DESTDIR_SUPPORT=	user-destdir

RCD_SCRIPTS=	nostromo
EGDIR=		${DESTDIR}/${PREFIX}/nostromo

USR_LOCAL=	/usr/local
VAR_NOSTROMO=	/var/nostromo

INSTALLATION_DIRS=	sbin
INSTALLATION_DIRS+=	var/nostromo
INSTALLATION_DIRS+=	${PKGMANDIR}/man8
INSTALLATION_DIRS+=	${EGDIR}
INSTALLATION_DIRS+=	${EGDIR}/logs
INSTALLATION_DIRS+=	${EGDIR}/icons
INSTALLATION_DIRS+=	${EGDIR}/htdocs
INSTALLATION_DIRS+=	${EGDIR}/htdocs/cgi-bin


SUBST_CLASSES+=		nostromo
SUBST_FILES.nostromo=	src/nhttpd/nhttpd.8 \
			src/nhttpd/main.c \
			conf/nhttpd.conf-dist
SUBST_SED.nostromo+=	-e 's,${VAR_NOSTROMO},${PREFIX}/nostromo,g'
SUBST_SED.nostromo+=	-e 's,${USR_LOCAL},${PREFIX},g'
SUBST_STAGE.nostromo=	post-patch

SUBST_CLASSES+=		perl
SUBST_FILES.perl=	htdocs/cgi-bin/printenv
SUBST_SED.perl+=	-e 's,/usr/bin/perl,/usr/bin/env perl,g'
SUBST_STAGE.perl=	post-patch

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/nhttpd/nhttpd \
		${DESTDIR}${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${WRKSRC}/src/tools/crypt \
		${DESTDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/src/nhttpd/nhttpd.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${MKDIR} -m 0775 ${EGDIR}/logs
	${MKDIR} ${EGDIR}/conf
	${INSTALL_DATA} ${WRKSRC}/conf/mimes ${EGDIR}/conf/
	${INSTALL_DATA} ${WRKSRC}/conf/nhttpd.conf-dist ${EGDIR}/conf/
	${MKDIR} ${EGDIR}/htdocs
	${INSTALL_DATA} ${WRKSRC}/htdocs/index.html ${EGDIR}/htdocs/
	${INSTALL_DATA} ${WRKSRC}/htdocs/nostromo.gif ${EGDIR}/htdocs/
	${MKDIR} ${EGDIR}/htdocs/cgi-bin
	${INSTALL_SCRIPT} ${WRKSRC}/htdocs/cgi-bin/printenv \
		${EGDIR}/htdocs/cgi-bin/
	${MKDIR} ${EGDIR}/icons
	${INSTALL_DATA} ${WRKSRC}/icons/dir.gif ${EGDIR}/icons/
	${INSTALL_DATA} ${WRKSRC}/icons/file.gif ${EGDIR}/icons/

.include "../../mk/bsd.pkg.mk"
