# $NetBSD: Makefile,v 1.2 2012/10/04 19:11:57 asau Exp $
#

DISTNAME=		Picasa-0.02
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/S/SA/SAMY/}

MAINTAINER=		rhaen@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Picasa/
COMMENT=		Perl module to access Google picasaweb image webspace

DEPENDS+=		p5-Term-ReadPassword>=0:../../devel/p5-Term-ReadPassword
DEPENDS+=		p5-XML-Parser>=0:../../textproc/p5-XML-Parser

PERL5_PACKLIST=			auto/Picasa/.packlist

pre-configure:
				cd ${WRKSRC}; \
						find . -name "*.orig" | xargs rm -f

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
