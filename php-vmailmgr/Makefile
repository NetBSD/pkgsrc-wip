# $NetBSD$

.include "../../wip/vmailmgr/Makefile.common"

PKGNAME=		php-vmailmgr-${VERSION}

DEPENDS+=		php-[0-9]*:${PHPPKGSRCDIR}

CONFIGURE_ARGS+=	--enable-php

BUILD_DIRS=		php
INSTALL_DIRS=		php

post-install:
	${INSTALL_DATA} ${WRKSRC}/${INSTALL_DIRS}/vmail.features \
		${DESTDIR}${PREFIX}/share/vmailmgr/php/README

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
