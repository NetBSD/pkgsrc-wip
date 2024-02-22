# $NetBSD$

.include "../../wip/vmailmgr/version.mk"

PKGNAME=	vmailmgr-${VERSION}
CATEGORIES=	mail

DEPENDS+=	vmailmgr-base>=${VERSION}:../../wip/vmailmgr-base
DEPENDS+=	vmailmgr-cgi>=${VERSION}:../../wip/vmailmgr-cgi
DEPENDS+=	vmailmgr-courier-imap>=${VERSION}:../../wip/vmailmgr-courier-imap
DEPENDS+=	vmailmgr-docs>=${VERSION}:../../wip/vmailmgr-docs
DEPENDS+=	vmailmgr-php>=${VERSION}:../../wip/vmailmgr-php
DEPENDS+=	vmailmgr-python>=${VERSION}:../../wip/vmailmgr-python

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
