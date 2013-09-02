# $NetBSD: Makefile,v 1.4 2013/09/02 19:48:41 schnoebe Exp $

DISTNAME=		serendipity-${VERSION}
VERSION=		1.7.2
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=php-blog/}

MAINTAINER=		tonnerre@NetBSD.org
HOMEPAGE=		http://s9y.org/
COMMENT=		Blogging tool written in php

USE_TOOLS+=		pax find rm

.include "../../mk/bsd.prefs.mk"
.include "../../lang/php/phpversion.mk"
.include "options.mk"

NO_BUILD=		yes
WRKSRC=			${WRKDIR}/serendipity

WWW_USER?=              ${APACHE_USER}
WWW_GROUP?=             ${APACHE_GROUP}

PKG_GROUPS_VARS+=	WWW_GROUP
PKG_USERS_VARS+=	WWW_USER
BUILD_DEFS+=		WWW_USER WWW_GROUP APACHE_USER APACHE_GROUP
DOCDIR=			${PREFIX}/share/doc/serendipity
S9YHOME=		${PREFIX}/share/serendipity
FILES_SUBST+=		S9YHOME=${S9YHOME}
MESSAGE_SUBST+=		DOCDIR=${DOCDIR}

INSTALLATION_DIRS+=	${DOCDIR} ${S9YHOME}

DOC_FILES=		CHANGED_FILES INSTALL INSTALL_EMBEDED INSTALL_SHARED
DOC_FILES+=		LICENSE NEWS NEWS_OLD README RELEASE UPGRADE

do-install:
.for f in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DESTDIR}${DOCDIR}
	${RM} ${WRKSRC}/docs/${f}
.endfor

	cd ${WRKSRC} && find . -name '.gitignore' -print | xargs rm -f
	cd ${WRKSRC} && pax -rw -pmp . ${DESTDIR}${S9YHOME}

.include "../../mk/bsd.pkg.mk"
