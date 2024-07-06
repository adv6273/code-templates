        vector<int> sgt;
        void build(vector<int>&nums, int s, int e, int i)
        {
            if(s==e)
            {
                sgt[i]=nums[s];
                return;
            }
            int mid=s+(e-s)/2;
            int left=2*i,right=2*i+1;
            build(nums,s,mid,left);
            build(nums,mid+1,e,right);
            sgt[i]=sgt[left]+sgt[right];
        }
        void update( vector<int>&v, int s, int e, int i, int pos, int val)
        {
            int n=v.size();
            if(s==e)
            {
                v[pos]=val;
                sgt[i]=val;
                return;
            }
            int mid=(s+e)/2;
            int left=2*i, right=2*i+1;
            if(mid<pos)
            {
                update(v,mid+1,e,right,pos,val);
            }
            else
                update(v,s,mid,left,pos,val);
            sgt[i]=sgt[left]+sgt[right];
            // sgt[i]=0+1;

        }
        int query( int s, int e, int i, int l, int r)
        {
            if(s>=l and e<=r)
            {
                return sgt[i];
            }
            if(r<s or l>e) return 0;
            int mid=(s+e)/2;
            int left_ans=query(s,mid,2*i,l,r);
            int right_ans=query(mid+1,e,2*i+1,l,r);
           return left_ans+right_ans;

        }