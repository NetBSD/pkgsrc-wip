# $NetBSD$

DISTNAME=	ez-pine-gpg_v0.4h
PKGNAME=	${DISTNAME:S/_v/-/}
CATEGORIES=	security
MASTER_SITES=	http://business-php.com/opensource/ez-pine-gpg/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://business-php.com/opensource/ez-pine-gpg/
COMMENT=	Scripts for using gpg with pine
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/ez-pine-gpg
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	bin share/doc/ez-pine-gpg

do-build:

do-install:
	for n in ez-pine-gpg-sign ez-pine-gpg-encrypt ez-pine-gpg-sign-and-encrypt ez-pine-gpg-symmetric ez-pine-gpg-incoming ez-pine-gpg-helper-recipient ez-pine-gpg-helper-sender; \
	do \
		${INSTALL_SCRIPT} ${WRKSRC}/$$n ${DESTDIR}${PREFIX}/bin; \
	done
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/ez-pine-gpg

.include "../../mk/bsd.pkg.mk"
