# $NetBSD: Makefile,v 1.10 2012/09/16 08:42:40 noud4 Exp $
#

PKGNAME=	${PYPKGPREFIX}-gettext-tools-0
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.python.org/topics/database/
COMMENT=	Python tools for development of I18N Python apps

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes
AUTO_MKDIRS=	yes

EXTRACT_ELEMENTS=		${PYSUBDIR}/Tools/i18n/*

PYTHON_PATCH_SCRIPTS=		Tools/i18n/msgfmt.py Tools/i18n/pygettext.py

# Why the hell it is not declared in python/pyvers.mk ?!
# 	-- tech-pkg@NetBSD.org
PLIST_SUBST+=			PYVERSSUFFIX=${PYVERSSUFFIX:Q}

do-patch:
	@echo "Patches ignored"

do-install:
	for a in ${PYTHON_PATCH_SCRIPTS}; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$$a ${DESTDIR}${PREFIX}/bin/`${BASENAME} $$a`-${PYVERSSUFFIX}; \
	done

.include "../../lang/python/application.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"
