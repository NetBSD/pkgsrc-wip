# $NetBSD$
#

PKGNAME=	p5-mha4mysql-node-0.56
GIT_COMMIT=	ef26bdeeeb16c4c1c5e37bdaa276d118ffdd85e7
DISTNAME=	${PKGNAME}-${GIT_COMMIT}
CATEGORIES=	databases perl5
MASTER_SITES=	-https://github.com/yoshinorim/mha4mysql-node/archive/${GIT_COMMIT}.tar.gz

MAINTAINER=	gianni-pkgsrc-wip@daprile.net
HOMEPAGE=	http://www.mysql.gr.jp/frame/modules/bwiki/
COMMENT=	Master High Availability Manager and tools for MySQL
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/mha4mysql-node-${GIT_COMMIT}
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-DBD-mysql>=1:../../databases/p5-DBD-mysql
DEPENDS+=	p5-DBI>=1.13:../../databases/p5-DBI
DEPENDS+=	p5-Module-Install>=0:../../devel/p5-Module-Install

PERL5_PACKLIST=		auto/mha4mysql/node/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
