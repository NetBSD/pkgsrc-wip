module github.com/aws/amazon-ecs-cli/ecs-cli

go 1.16

require (
	github.com/Azure/go-ansiterm v0.0.0-20170929234023-d6e3b3328b78
	github.com/Microsoft/go-winio v0.3.7
	github.com/Microsoft/hcsshim v0.8.9
	github.com/aws/aws-sdk-go v1.34.9
	github.com/awslabs/amazon-ecr-credential-helper v0.4.0
	github.com/containerd/containerd v1.3.4
	github.com/containerd/continuity v0.0.0-20200413184840-d3ef23f19fbb
	github.com/cpuguy83/go-md2man v1.0.10
	github.com/davecgh/go-spew v1.1.0
	github.com/docker/cli v0.0.0-20200617172703-0ed913b885c8
	github.com/docker/distribution v2.7.1+incompatible
	github.com/docker/go-connections v0.4.0
	github.com/docker/go-units v0.4.0
	github.com/docker/libcompose v0.4.1-0.20171025083809-57bd716502dc
	github.com/flynn/go-shlex v0.0.0-20150515145356-3f9db97f8568
	github.com/fsouza/go-dockerclient v1.6.5
	github.com/go-ini/ini v1.60.1
	github.com/gogo/protobuf v0.0.0-20180104102128-160de10b2537
	github.com/golang/mock v1.4.4
	github.com/golang/protobuf v1.4.2
	github.com/imdario/mergo v0.3.4
	github.com/jmespath/go-jmespath v0.0.0-20180206201540-c2b33e8439af
	github.com/konsorten/go-windows-terminal-sequences v1.0.3
	github.com/mattn/go-shellwords v1.0.3
	github.com/mitchellh/go-homedir v0.0.0-20160301183130-981ab348d865
	github.com/mitchellh/mapstructure v0.0.0-20180220230111-00c29f56e238
	github.com/moby/moby v17.12.0-ce-rc1.0.20200618181300-9dc6525e6118+incompatible
	github.com/morikuni/aec v1.0.0
	github.com/opencontainers/go-digest v1.0.0-rc1
	github.com/opencontainers/image-spec v1.0.1-0.20171125024018-577479e4dc27
	github.com/opencontainers/runc v1.0.0-rc2.0.20161227072456-f376b8033d2c
	github.com/pkg/errors v0.9.1
	github.com/pmezard/go-difflib v1.0.0
	github.com/shurcooL/sanitized_anchor_name v1.0.0
	github.com/sirupsen/logrus v1.6.0
	github.com/stretchr/testify v1.6.1
	github.com/urfave/cli v1.22.0
	github.com/xeipuuv/gojsonpointer v0.0.0-20151027082146-e0fe6f683076
	github.com/xeipuuv/gojsonreference v0.0.0-20150808065054-e02fc20de94c
	github.com/xeipuuv/gojsonschema v0.0.0-20161119180151-e18f0065e8c1
	golang.org/x/net v0.0.0-20170308210134-a6577fac2d73
	golang.org/x/sync v0.0.0-20200317015054-43a5402ce75a
	golang.org/x/sys v0.0.0-20180110071738-810d70003458
	google.golang.org/genproto v0.0.0-20200617032506-f1bdc9086088
	google.golang.org/grpc v1.29.1
	google.golang.org/protobuf v1.24.0
	gopkg.in/yaml.v2 v2.3.0
	gopkg.in/yaml.v3 v3.0.0-20200615113413-eeeca48fe776
)

replace github.com/docker/docker 9dc6525e6118a25fab2be322d1914740ea842495 => github.com/moby/moby v17.12.0-ce-rc1.0.20200618181300-9dc6525e6118+incompatible
