# $Id: Makefile,v 1.5 2013/10/01 20:52:48 tonnerre Exp $
# $NetBSD: Makefile,v 1.5 2013/10/01 20:52:48 tonnerre Exp $

DISTNAME=		serendipity-${VERSION}
# Please contact the maintainer when changing the line below.
VERSION=		1.7.3
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=php-blog/}

MAINTAINER=		tonnerre@NetBSD.org
HOMEPAGE=		http://s9y.org/
COMMENT=		Blogging tool written in php

USE_TOOLS+=		pax find rm

REPLACE_INTERPRETER+=	bash perl
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	/bin/sh
REPLACE_FILES.bash=	lang/UTF-8/recode.sh lang/addlang.sh lang/append.sh
REPLACE.perl.old=	/usr/bin/perl
REPLACE.perl.new=	${PREFIX}/bin/perl
REPLACE_FILES.perl=	htmlarea/plugins/SpellChecker/spell-check-logic.cgi

.include "../../mk/bsd.prefs.mk"
.include "../../lang/php/phpversion.mk"
.include "options.mk"

NO_BUILD=		yes
WRKSRC=			${WRKDIR}/serendipity

WWW_USER?=		${APACHE_USER}
WWW_GROUP?=		${APACHE_GROUP}

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
	${INSTALL_DATA} ${WRKSRC}/README.markdown ${DESTDIR}${DOCDIR}
	${RM} ${WRKSRC}/README.markdown
.for f in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DESTDIR}${DOCDIR}
	${RM} ${WRKSRC}/docs/${f}
.endfor

	cd ${WRKSRC} && find . -name '.gitignore' -print | xargs rm -f
	cd ${WRKSRC} && pax -rw -pmp . ${DESTDIR}${S9YHOME}

.include "../../mk/bsd.pkg.mk"
