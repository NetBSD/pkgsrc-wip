# $NetBSD: Makefile,v 1.12 2014/01/25 10:45:28 thomasklausner Exp $
#

PKGNAME=	${PYPKGPREFIX}-gettext-tools-0
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.python.org/topics/database/
COMMENT=	Python tools for development of I18N Python apps

NO_BUILD=	yes
AUTO_MKDIRS=	yes

EXTRACT_ELEMENTS=		${PYSUBDIR}/Tools/i18n/*

REPLACE_PYTHON=		Tools/i18n/msgfmt.py Tools/i18n/pygettext.py

# Why the hell it is not declared in python/pyvers.mk ?!
# 	-- tech-pkg@NetBSD.org
PLIST_SUBST+=			PYVERSSUFFIX=${PYVERSSUFFIX:Q}

do-patch:
	@echo "Patches ignored"

do-install:
	for a in ${REPLACE_PYTHON}; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$$a ${DESTDIR}${PREFIX}/bin/`${BASENAME} $$a`-${PYVERSSUFFIX}; \
	done

.include "../../lang/python/application.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"
