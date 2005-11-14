# $NetBSD: Makefile,v 1.1.1.1 2005/11/14 15:16:58 jtonio Exp $
#

DISTNAME=	signing-party_0.4.4.orig
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/s/signing-party/}

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://pgp-tools.alioth.debian.org/
COMMENT=	Various OpenPGP related tools

DEPENDS+=	gnupg>=1.4.2:../../security/gnupg
DEPENDS+=	p5-Text-Template-[0-9]*:../../textproc/p5-Text-Template
DEPENDS+=        p5-GnuPG-Interface>=0.34:../../security/p5-GnuPG-Interface

WRKSRC=		${WRKDIR}/signing-party-0.4.4
USE_TOOLS+=	gmake pod2man
REPLACE_PERL=	caff/caff caff/pgp-fixkey caff/pgp-clean \
		gpg-key2ps/gpg-key2ps gpgsigs/gpgsigs \
		gpglist/gpglist keylookup/keylookup

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/caff/caff ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/caff/pgp-fixkey ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/caff/pgp-clean ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/gpg-key2ps/gpg-key2ps ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/gpgsigs/gpgsigs ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/gpglist/gpglist ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/keylookup/keylookup ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/gpg-mailkeys/gpg-mailkeys ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/caff/caff.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/caff/pgp-fixkey.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/caff/pgp-clean.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/gpg-key2ps/gpg-key2ps.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/gpgsigs/gpgsigs.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/gpglist/gpglist.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/keylookup/keylookup.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/gpg-mailkeys/gpg-mailkeys.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
