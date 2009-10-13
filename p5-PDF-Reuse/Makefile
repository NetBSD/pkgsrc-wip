# $NetBSD: Makefile,v 1.3 2009/10/13 20:21:08 leot1990 Exp $

DISTNAME=		PDF-Reuse-0.35
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=PDF/}

MAINTAINER=		phil@cs.wwu.edu
HOMEPAGE=		http://search.cpan.org/dist/PDF-Reuse/
COMMENT=		Perl module to reuse PDF templates

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-IO-Compress>=0:../../devel/p5-IO-Compress
DEPENDS+=		p5-Font-TTF>=0:../../fonts/p5-Font-TTF
DEPENDS+=		p5-Text-PDF>=0:../../textproc/p5-Text-PDF
DEPENDS+=		p5-Digest-MD5>=2.35:../../security/p5-Digest-MD5

PERL5_PACKLIST=	auto/PDF/Reuse/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
