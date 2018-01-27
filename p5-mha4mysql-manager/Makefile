# $NetBSD$
#

PKGNAME=	p5-mha4mysql-manager-0.57
GIT_COMMIT=	fea77e93168c8212550c21f542fec48f5d978535
DISTNAME=	${PKGNAME}-${GIT_COMMIT}
CATEGORIES=	databases perl5
MASTER_SITES=	-https://github.com/yoshinorim/mha4mysql-manager/archive/${GIT_COMMIT}.tar.gz

MAINTAINER=	gianni-pkgsrc-wip@daprile.net
HOMEPAGE=	http://www.mysql.gr.jp/frame/modules/bwiki/
COMMENT=	Master High Availability Manager and tools for MySQL
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/mha4mysql-manager-${GIT_COMMIT}
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-DBD-mysql>=4:../../databases/p5-DBD-mysql
DEPENDS+=	p5-DBI>=1:../../databases/p5-DBI
DEPENDS+=	p5-Config-Tiny>=2:../../devel/p5-Config-Tiny
DEPENDS+=	p5-Log-Dispatch>=2:../../devel/p5-Log-Dispatch
DEPENDS+=	p5-Parallel-ForkManager>=0.7:../../devel/p5-Parallel-ForkManager
DEPENDS+=	p5-Time-HiRes>=1:../../time/p5-Time-HiRes
DEPENDS+=	p5-mha4mysql-node>=0.56:../../wip/p5-mha4mysql-node

PERL5_PACKLIST=		auto/mha4mysql/manager/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
