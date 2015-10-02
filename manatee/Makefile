# $NetBSD: Makefile,v 1.15 2014/04/02 18:38:12 asau Exp $

DISTNAME=		manatee-1.8.4.1
PKGREVISION=		3
CATEGORIES=		biology
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=manatee/}

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://sourceforge.net/projects/manatee/
COMMENT=		Web-based gene evaluation and genome annotation tool

WRKSRC=			${WRKDIR}/manatee

DEPENDS+=		p5-CGI>=2.91:../../www/p5-CGI
DEPENDS+=		p5-DBD-{mysql,percona}*-[0-9]*:../../databases/p5-DBD-mysql
DEPENDS+=		p5-XML-Parser>=2.31:../../textproc/p5-XML-Parser
DEPENDS+=		p5-XML-Simple>=2.07:../../textproc/p5-XML-Simple
DEPENDS+=		p5-HTML-Template>=2.6:../../www/p5-HTML-Template
DEPENDS+=		p5-GD>=2.07:../../graphics/p5-GD
DEPENDS+=		p5-GDGraph>=1.33nb1:../../graphics/p5-GDGraph
DEPENDS+=		p5-GDTextUtil>=0.80nb1:../../graphics/p5-GDTextUtil
#DEPENDS+=		p5-Storable>=2.06:../../devel/p5-Storable
DEPENDS+=		p5-Date-Manip>=5.40:../../devel/p5-Date-Manip
DEPENDS+=		p5-Tree-DAG_Node>=1.04:../../devel/p5-Tree-DAG_Node
DEPENDS+=		p5-DBD-Sybase>=0.94:../../databases/p5-DBD-Sybase

# Depend on default MySQL server:
DEPENDS+=		mysql-server>=5.0:../../databases/mysql$(MYSQL_VERSION_DEFAULT)-server


USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

pre-configure:
	cd ${WRKSRC}; ${AUTOCONF}

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../www/apache24/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
