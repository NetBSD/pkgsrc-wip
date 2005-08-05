# $NetBSD: Makefile,v 1.4 2005/08/05 18:40:55 kuli0020 Exp $

DISTNAME=	Pod-Tree-1.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Pod-Tree/
COMMENT=	Create a static syntax tree for a POD

DEPENDS+=	p5-HTML-Stream>=1.49:../../wip/p5-HTML-Stream
DEPENDS+=	p5-Pod-Escapes>=1.02:../../textproc/p5-Pod-Escapes

PERL5_PACKLIST= auto/Pod/Tree/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
