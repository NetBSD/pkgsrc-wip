# $NetBSD: Makefile,v 1.2 2012/03/31 21:45:07 bubuchka Exp $
#

DISTNAME=	kyotocabinet-perl-1.19
PKGNAME=	p5-KyotoCabinet-${DISTNAME:S/kyotocabinet-perl-//}
CATEGORIES=	databases devel
MASTER_SITES=	http://fallabs.com/kyotocabinet/perlpkg/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fallabs.com/kyotocabinet/
COMMENT=	Perl binding for Kyoto Cabinet
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/KyotoCabinet/.packlist

.include "../../wip/kyotocabinet/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
