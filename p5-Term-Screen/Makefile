# $NetBSD: Makefile,v 1.4 2005/10/05 02:51:45 jgoamakf Exp $

DISTNAME=	Term-Screen-1.03
PKGNAME=	p5-Term-Screen-1.03
CATEGORIES=	perl5 wip devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Term-Screen/
COMMENT=	Term::Cap based screen positioning module

PKG_INSTALLATION_TYPES= overwrite pkgviews

PERL5_PACKLIST=		auto/Term/Screen/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
