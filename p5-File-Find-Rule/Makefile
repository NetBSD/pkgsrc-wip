# $NetBSD: Makefile,v 1.1.1.1 2005/04/04 08:19:48 jgoamakf Exp $

DISTNAME=	File-Find-Rule-0.28
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ffr
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/File-Find-Rule/
COMMENT=	Alternative interface to File::Find

DEPENDS+=	p5-Number-Compare>=0.01:../../wip/p5-Number-Compare
DEPENDS+=	p5-Text-Glob>=0.06:../../wip/p5-Text-Glob

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/File/Find/Rule/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
