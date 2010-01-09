# $NetBSD: Makefile,v 1.1 2010/01/09 17:59:21 pettai Exp $
#

VER=		1.9.0
DISTNAME=	moin-${VER}
PKGNAME=        ${PYPKGPREFIX}-MoinMoin-${VER}
CATEGORIES=	www
MASTER_SITES=	http://static.moinmo.in/files/

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://moinmo.in/
COMMENT=	Advanced, easy to use and extensible WikiEngine
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= yes

REPLACE_PYTHON=	MoinMoin/i18n/tools/markup15to16.py \
		MoinMoin/i18n/tools/po2wiki.py \
		MoinMoin/i18n/tools/prepend.py \
		MoinMoin/i18n/tools/wiki2po.py

REPLACE_PERL=	MoinMoin/web/static/htdocs/applets/FCKeditor/editor/dialog/fck_spellerpages/spellerpages/server-scripts/spellchecker.pl

USE_LANGUAGES=	# none

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
