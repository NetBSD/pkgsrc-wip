# $NetBSD$

DISTNAME=	redmine-4.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/redmine/redmine41/}
CATEGORIES=	devel
MASTER_SITES=	https://www.redmine.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.redmine.org/
COMMENT=	Flexible project management web application
LICENSE=	gnu-gpl-v2 # and so on.
NO_CONFIGURE=	yes
NO_BUILD=	yes

RUBY_VERSIONS_ACCEPTED=	25 26

.include "../../lang/ruby/rubyversion.mk"

DEPENDS+=	${RUBY_PKGPREFIX}-bundler>=1.5.0:../../misc/ruby-bundler
DEPENDS+=	${RUBY_PKGPREFIX}-rails52-[0-9]*:../../www/ruby-rails52
DEPENDS+=	${RUBY_PKGPREFIX}-rouge>=3.12:../../www/ruby-rouge
DEPENDS+=	${RUBY_PKGPREFIX}-request_store>=1.4.1:../../wip/ruby-request_store
DEPENDS+=	${RUBY_PKGPREFIX}-mini_mime>=1.0.1<1.1:../../mail/ruby-mini_mime
DEPENDS+=	${RUBY_PKGPREFIX}-actionpack52-xml_parser-[0-9]*:../../wip/ruby-actionpack52-xml_parser
DEPENDS+=	${RUBY_PKGPREFIX}-roadie-rails52>=2.1.0<2.2:../../wip/ruby-roadie-rails52
DEPENDS+=	${RUBY_PKGPREFIX}-mimemagic-[0-9]*:../../misc/ruby-mimemagic
DEPENDS+=	${RUBY_PKGPREFIX}-mail>=2.7.1<2.8:../../mail/ruby-mail
DEPENDS+=	${RUBY_PKGPREFIX}-csv>=3.1.1<3.2:../../wip/ruby-csv
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.10.0<1.11:../../textproc/ruby-nokogiri
DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=1.6.0:../../devel/ruby-i18n
DEPENDS+=	${RUBY_PKGPREFIX}-rbpdf>=1.20.0<1.21:../../wip/ruby-rbpdf
DEPENDS+=	${RUBY_PKGPREFIX}-tzinfo-data-[0-9]*:../../time/ruby-tzinfo-data
DEPENDS+=	${RUBY_PKGPREFIX}-net-ldap>=0.16.0<0.17:../../net/ruby-net-ldap
DEPENDS+=	${RUBY_PKGPREFIX}-ruby-openid>=2.9.2<2.10:../../security/ruby-ruby-openid
DEPENDS+=	${RUBY_PKGPREFIX}-rack-openid-[0-9]*:../../security/ruby-rack-openid
DEPENDS+=	${RUBY_PKGPREFIX}-mini-magick>=4.9.2<4.10:../../graphics/ruby-mini-magick
DEPENDS+=	${RUBY_PKGPREFIX}-redcarpet>=3.4.0<3.6.0:../../textproc/ruby-redcarpet

.include "options.mk"

RM_DIR=		share/${RUBY_PKGPREFIX}-redmine41

REPLACE_RUBY+=	${DISTNAME}/bin/*
REPLACE_RUBY+=	${DISTNAME}/extra/mail_handler/rdm-mailhandler.rb
REPLACE_RUBY+=	${DISTNAME}/extra/svn/reposman.rb
REPLACE_RUBY+=	${DISTNAME}/public/dispatch.fcgi.example

SUBST_CLASSES+=		shell
SUBST_FILES.shell=	${DESTDIR}${PREFIX}/bin/redmine41_*${RUBY_SUFFIX}.sh
SUBST_MESSAGE.shell=	Fixing paths in helper shell scripts.
SUBST_VARS.shell=	PREFIX
SUBST_VARS.shell+=	RUBY
SUBST_VARS.shell+=	RM_DIR
SUBST_STAGE.shell=	post-install

MESSAGE_SUBST+=	RM_DIR=${RM_DIR}

USE_LANGUAGES=	# none

EGDIR=		${PREFIX}/share/examples/${RUBY_PKGPREFIX}-redmine41
INSTALLATION_DIRS=	bin ${EGDIR} ${RM_DIR} ${RM_DIR}/config

CONF_FILES+=	${EGDIR}/configuration.yml.example \
			${RM_DIR}/config/configuration.yml
CONF_FILES+=	${EGDIR}/database.yml.example \
			${RM_DIR}/config/database.yml
CONF_FILES+=	${EGDIR}/additional_environment.rb.example \
			${RM_DIR}/config/additional_environment.rb

.include "../../mk/bsd.prefs.mk"

APACHE_USER?=	www
APACHE_GROUP?=	www
PKG_GROUPS=	${APACHE_GROUP}
PKG_USERS=	${APACHE_USER}:${APACHE_GROUP}
BUILD_DEFS+=	APACHE_GROUP APACHE_USER
FILES_SUBST+=	WWWGRP=${APACHE_GROUP} WWWOWN=${APACHE_USER} \
		RM_DIR=${RM_DIR}

do-install:
	cd ${WRKSRC} && ${FIND} . -type d -exec ${INSTALL_DATA_DIR} \
		${DESTDIR}${PREFIX}/${RM_DIR}/{} \;
	cd ${WRKSRC} && ${FIND} . -type f ! -name "*.orig" -exec \
		${INSTALL_DATA} {} ${DESTDIR}${PREFIX}/${RM_DIR}/{} \;
	${INSTALL_SCRIPT} ${FILESDIR}/redmine41_migrate_plugins.sh \
		${DESTDIR}${PREFIX}/bin/redmine41_migrate_plugins${RUBY_SUFFIX}.sh
	${INSTALL_SCRIPT} ${FILESDIR}/redmine41_generate_secret_token.sh \
		${DESTDIR}${PREFIX}/bin/redmine41_generate_secret_token${RUBY_SUFFIX}.sh
	${INSTALL_SCRIPT} ${FILESDIR}/redmine41_migrate_db.sh \
		${DESTDIR}${PREFIX}/bin/redmine41_migrate_db${RUBY_SUFFIX}.sh
	${INSTALL_SCRIPT} ${FILESDIR}/redmine41_load_default_data.sh \
		${DESTDIR}${PREFIX}/bin/redmine41_load_default_data${RUBY_SUFFIX}.sh
	${TOUCH} ${DESTDIR}${PREFIX}/${RM_DIR}/Gemfile.lock

post-install: unicorn-post-install
	${FIND} ${DESTDIR}/ -name ".*" \( -type f -or -type d \) | xargs rm -rf
	${MV} ${DESTDIR}${PREFIX}/${RM_DIR}/config/configuration.yml.example \
		${DESTDIR}/${EGDIR}
	${MV} ${DESTDIR}${PREFIX}/${RM_DIR}/config/database.yml.example \
		${DESTDIR}/${EGDIR}
	${MV} ${DESTDIR}${PREFIX}/${RM_DIR}/config/additional_environment.rb.example \
		${DESTDIR}/${EGDIR}

.include "../../lang/ruby/replace.mk"
.include "../../mk/bsd.pkg.mk"
