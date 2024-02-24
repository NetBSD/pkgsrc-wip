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
DEPENDS+=	php-vmailmgr>=${VERSION}:../../wip/php-vmailmgr
DEPENDS+=	py-vmailmgr>=${VERSION}:../../wip/py-vmailmgr

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
