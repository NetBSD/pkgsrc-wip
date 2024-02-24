# $NetBSD$

.include "../../wip/vmailmgr/version.mk"

PKGNAME=	vmailmgr-${VERSION}
CATEGORIES=	mail

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://untroubled.org/vmailmgr/
COMMENT=	Virtual domain manager for qmail

DEPENDS+=	vmailmgr-base>=${VERSION}:../../wip/vmailmgr-base
DEPENDS+=	vmailmgr-cgi>=${VERSION}:../../wip/vmailmgr-cgi
DEPENDS+=	vmailmgr-courier-imap>=${VERSION}:../../wip/vmailmgr-courier-imap
DEPENDS+=	vmailmgr-docs>=${VERSION}:../../wip/vmailmgr-docs
DEPENDS+=	vmailmgr-php>=${VERSION}:../../wip/vmailmgr-php
DEPENDS+=	vmailmgr-${PYPKGPREFIX}>=${VERSION}:../../wip/vmailmgr-python

META_PACKAGE=	yes

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
