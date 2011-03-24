# $NetBSD: Makefile,v 1.1 2011/03/24 16:27:50 astforge Exp $
#

DISTNAME=	nostromo-1.9.4
PKGREVISION=	1
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.nazgul.ch/dev/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ast@marabu.ch
COMMENT=	A fast, secure HTTP/1.1 CGI/1.1 SSL IPv4/IPv6 webserver
LICENSE=	modified-bsd
HOMEPAGE=	http://www.nazgul.ch/dev_nostromo.html

USE_LANGUAGES=	c
USE_TOOLS=	sed

NOSTROMO_DIR?=	${PREFIX}/nostromo

RCD_SCRIPTS=    nostromo
EGDIR=		nostromo
VAR_NOSTROMO=	/var/nostromo
USR_LOCAL=	/usr/local
CONF_FILES=     ${EGDIR}/conf/nhttpd.conf-dist ${EGDIR}/conf/nhttpd.conf

PKG_DESTDIR_SUPPORT=    user-destdir
INSTALLATION_DIRS=      $(PKGMANDIR)/man8 $(EG_DIR)

SUBST_CLASSES+=		usrlocal
SUBST_FILES.usrlocal=	src/nhttpd/nhttpd.8
SUBST_SED.usrlocal+=	-e 's,${USR_LOCAL},${PREFIX},g'
SUBST_STAGE.usrlocal=	post-patch

SUBST_CLASSES+=		nostromo
SUBST_FILES.nostromo=	src/nhttpd/nhttpd.8 \
			src/nhttpd/main.c \
			conf/nhttpd.conf-dist
SUBST_SED.nostromo+=	-e 's,${VAR_NOSTROMO},${PREFIX}/${EGDIR},g'
SUBST_STAGE.nostromo=	post-patch

SUBST_CLASSES+=		perl
SUBST_FILES.perl=	htdocs/cgi-bin/printenv
SUBST_SED.perl+=	-e 's,/usr/bin/perl,/usr/bin/env perl,g'
SUBST_STAGE.perl=	post-patch

USE_RC_SUBR=	nostromo.sh

MAN8=		nhttpd.8

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/src/nhttpd/nhttpd ${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKSRC}/src/tools/crypt ${PREFIX}/sbin
	@${INSTALL_MAN} ${WRKSRC}/src/nhttpd/nhttpd.8 ${PREFIX}/man/man8
	@${MKDIR} -m 0775 ${NOSTROMO_DIR}/logs
	@${MKDIR} ${NOSTROMO_DIR}/conf
	@${INSTALL_DATA} ${WRKSRC}/conf/mimes ${NOSTROMO_DIR}/conf
	@${INSTALL_DATA} ${WRKSRC}/conf/nhttpd.conf-dist ${NOSTROMO_DIR}/conf
	@${MKDIR} ${NOSTROMO_DIR}/htdocs
	@${INSTALL_DATA} ${WRKSRC}/htdocs/index.html ${NOSTROMO_DIR}/htdocs
	@${INSTALL_DATA} ${WRKSRC}/htdocs/nostromo.gif ${NOSTROMO_DIR}/htdocs
	@${MKDIR} ${NOSTROMO_DIR}/htdocs/cgi-bin
	@${INSTALL_SCRIPT} ${WRKSRC}/htdocs/cgi-bin/printenv \
		${NOSTROMO_DIR}/htdocs/cgi-bin
	@${MKDIR} ${NOSTROMO_DIR}/icons
	@${INSTALL_DATA} ${WRKSRC}/icons/dir.gif ${NOSTROMO_DIR}/icons
	@${INSTALL_DATA} ${WRKSRC}/icons/file.gif ${NOSTROMO_DIR}/icons

.include "../../mk/bsd.pkg.mk"
