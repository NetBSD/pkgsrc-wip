# $NetBSD: Makefile,v 1.3 2006/05/19 16:51:28 ykomatsu Exp $
#

DISTNAME=		Crypt-PasswdMD5-1.3
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-PasswdMD5/
COMMENT=		Perl5 MD5 Password implementation

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=               p5-Digest-MD5>=2.33:../../security/p5-Digest-MD5

CRYPTO=			YES
PERL5_PACKLIST=		auto/Crypt/PasswdMD5/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
