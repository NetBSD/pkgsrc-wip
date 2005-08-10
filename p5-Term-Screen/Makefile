# $NetBSD: Makefile,v 1.3 2005/08/10 12:52:34 jgoamakf Exp $

DISTNAME=	Term-Screen-1.03
PKGNAME=	p5-Term-Screen-1.03
CATEGORIES=	perl5 wip devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Term::Cap based screen positioning module

PKG_INSTALLATION_TYPES= overwrite pkgviews

PERL5_PACKLIST=		auto/Term/Screen/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
