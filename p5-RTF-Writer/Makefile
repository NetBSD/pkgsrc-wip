# $NetBSD: Makefile,v 1.2 2012/10/04 19:11:58 asau Exp $

DISTNAME=		RTF-Writer-1.11
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=RTF/}

MAINTAINER=		tonnerre@bsdprojects.net
HOMEPAGE=		http://search.cpan.org/dist/RTF-Writer/
COMMENT=		Perl module for generating documents in Rich Text Format

DEPENDS+=		p5-Image-Size-[0-9]*:../../graphics/p5-Image-Size


PERL5_PACKLIST=		auto/RTF/Writer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
