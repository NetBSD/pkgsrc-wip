# $NetBSD: Makefile,v 1.1.1.1 2005/05/04 00:34:03 geeohgeegeeoh Exp $
#

DISTNAME=		Crypt-PasswdMD5-1.3
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-PasswdMD5/
COMMENT=		Perl5 MD5 Password implementation

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=               p5-Digest-MD5>=2.33:../../security/p5-Digest-MD5

CRYPTO=			YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/PasswdMD5/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
