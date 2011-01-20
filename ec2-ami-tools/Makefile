# $NetBSD: Makefile,v 1.1.1.1 2011/01/20 00:30:13 jym-netbsd Exp $
#

PKGNAME=	ec2-ami-tools-1.3.57676
DISTNAME=	ec2-ami-tools-1.3-57676

.include "../../wip/ec2-api-tools/Makefile.common"

CATEGORIES=	misc
MASTER_SITES=	http://s3.amazonaws.com/ec2-downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	jym@NetBSD.org
HOMEPAGE=	http://aws.amazon.com/developertools/368
COMMENT=	Amazon EC2 AMI Tools (bundle, create, upload AMIs to S3)
LICENSE=	amazon-software-license

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS=	gzip openssl pax tee

DEPENDS+=	curl-[0-9]*:../../www/curl
DEPENDS+=	rsync-[0-9]*:../../net/rsync
DEPENDS+=	ruby${RUBY_VER}-base>=1.8.2:../../lang/ruby${RUBY_VER}-base

NO_BUILD=	yes

.include "../../mk/bsd.prefs.mk"

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	/bin/sh
REPLACE_FILES.bash=	bin/*

SUBST_CLASSES+=		ec2-home
SUBST_STAGE.ec2-home=	pre-configure
SUBST_FILES.ec2-home=	bin/*
SUBST_SED.ec2-home+=	-e 's|\$${EC2_HOME.*}|${EC2_HOME}/}|g'
SUBST_MESSAGE.ec2-home=	Setting EC2_HOME default path.

SUBST_CLASSES+=		ruby
SUBST_STAGE.ruby=	pre-configure
SUBST_FILES.ruby=	bin/*
SUBST_SED.ruby+=	-e 's|^ruby |${RUBY_NAME} |g'
SUBST_MESSAGE.ruby=	Fixing ruby interpreter name.

INSTALLATION_DIRS+=	bin amazon-ec2
INSTALLATION_DIRS+=	amazon-ec2/etc amazon-ec2/bin amazon-ec2/lib

post-extract:
	find ${WRKSRC}/lib ${WRKSRC}/etc -type d -exec \
		${CHMOD} ${PKGDIRMODE} {} \;
	find ${WRKSRC}/lib ${WRKSRC}/etc -type f -exec \
		${CHMOD} ${NONBINMODE} {} \;

do-install:
	cd ${WRKSRC}/etc && pax -rwpam . ${DESTDIR}${EC2_HOME}/etc
	cd ${WRKSRC}/lib && pax -rwpam . ${DESTDIR}${EC2_HOME}/lib

	cd ${WRKSRC}/bin && for f in *; do			\
		${INSTALL_SCRIPT} $$f ${DESTDIR}${EC2_HOME}/bin;\
		${LN} -sf ${DESTDIR}${EC2_HOME}/bin/$$f		\
			${DESTDIR}${PREFIX}/bin;		\
	done

.include "../../lang/ruby/replace.mk"
.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
