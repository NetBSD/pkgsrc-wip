# $NetBSD: Makefile,v 1.5 2005/04/11 21:15:00 tvierling Exp $
#

PKGNAME=	${PYPKGPREFIX}-gettext-tools-0
CATEGORIES=	databases

MAINTAINER=	dotz@irc.pl
HOMEPAGE=	http://www.python.org/topics/database/
COMMENT=	Python tools for development of I18N Python apps

NO_BUILD=	# defined

EXTRACT_ELEMENTS=		${PYSUBDIR}/Tools/i18n/*

PYTHON_PATCH_SCRIPTS=		Tools/i18n/msgfmt.py Tools/i18n/pygettext.py

# Why the hell it is not declared in python/pyvers.mk ?!
# 	-- dotz@irc.pl
PLIST_SUBST+=			PYVERSSUFFIX=${PYVERSSUFFIX}

do-patch:
	@echo "Patches ignored"

do-install:
	for a in ${PYTHON_PATCH_SCRIPTS}; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$$a ${PREFIX}/bin/`${BASENAME} $$a`-${PYVERSSUFFIX}; \
	done

.include "../../lang/python/application.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"
