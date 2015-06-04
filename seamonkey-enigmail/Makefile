# $NetBSD: Makefile,v 1.2 2015/06/04 21:41:25 krytarowski Exp $

.include "../../wip/thunderbird-enigmail/Makefile.common"

PKGNAME=	seamonkey-${DISTNAME}
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GnuPG support for www/seamonkey

# Minimal requirements are here: https://www.enigmail.net/download/source.php
DEPENDS+=		seamonkey>=2.29:../../www/seamonkey

# Path used during the install stage
XPIDIR=		${PREFIX}/lib/seamonkey/extensions

.include "../../mk/bsd.pkg.mk"
