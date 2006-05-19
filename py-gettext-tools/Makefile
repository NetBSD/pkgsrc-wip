# $NetBSD: Makefile,v 1.9 2006/05/19 16:51:32 ykomatsu Exp $
#

PKGNAME=	${PYPKGPREFIX}-gettext-tools-0
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.python.org/topics/database/
COMMENT=	Python tools for development of I18N Python apps

NO_BUILD=	yes

EXTRACT_ELEMENTS=		${PYSUBDIR}/Tools/i18n/*

PYTHON_PATCH_SCRIPTS=		Tools/i18n/msgfmt.py Tools/i18n/pygettext.py

# Why the hell it is not declared in python/pyvers.mk ?!
# 	-- tech-pkg@NetBSD.org
PLIST_SUBST+=			PYVERSSUFFIX=${PYVERSSUFFIX:Q}

do-patch:
	@echo "Patches ignored"

do-install:
	for a in ${PYTHON_PATCH_SCRIPTS}; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$$a ${PREFIX}/bin/`${BASENAME} $$a`-${PYVERSSUFFIX}; \
	done

.include "../../lang/python/application.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"
