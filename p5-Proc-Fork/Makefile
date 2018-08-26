# $NetBSD: Makefile,v 1.4 2014/10/09 14:06:29 thomasklausner Exp $

DISTNAME=	Proc-Fork-0.806
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Proc-Fork/
COMMENT=	Simple, intuitive interface to the fork() system call
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Exporter-Tidy-[0-9]*:../../wip/p5-Exporter-Tidy

PERL5_PACKLIST=		auto/Proc/Fork/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
